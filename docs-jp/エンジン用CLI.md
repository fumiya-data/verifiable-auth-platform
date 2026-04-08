# エンジン CLI 契約

この文書は [`../docs/engine-cli-contract.md`](../docs/engine-cli-contract.md) の日本語版です。

この文書は、C エンジンが公開する安定したコマンドライン境界と JSON 境界を定義します。
Go TUI や将来の外部ツールは、この境界を公開インターフェースとして扱わなければならず、
engine の storage file を直接読みにいってはいけません。

上位のシステム意味論は [`仕様書.md`](./仕様書.md)、
形式仕様と C 実装の対照は
[`Lean仕様とC言語エンジンの対照表.md`](./Lean仕様とC言語エンジンの対照表.md) を参照してください。

## 対象範囲

engine CLI は 6 つのコマンドを公開します。

- `register`
- `login`
- `change-password`
- `logout`
- `show-audit`
- `show-metrics`

前者 4 つは engine state を変更し得ます。後者 2 つは読み取り専用の observability query です。

## 呼び出し形式

一般形は次のとおりです。

```text
engine_cli <command> [options]
```

engine は 1 つの位置引数 command と、次の option を受け取ります。

- `--data-dir <path>`
  - 任意。既定値は `.engine-data`
- `--login-id <value>`
  - `register` と `login` に必須
- `--password <value>`
  - `register` と `login` に必須
- `--old-password <value>`
  - `change-password` に必須
- `--new-password <value>`
  - `change-password` に必須

未知の option、option value の欠落、必須引数の欠落、未知 command 名は
`invalid_request` JSON 応答と usage error exit code を返します。

## `--data-dir` 配下の永続化ファイル

CLI は、設定された data directory 配下で次の engine 管理ファイルを使います。

- `users.tsv`
- `session.txt`
- `audit.log`

これらのファイルは engine の実装詳細です。外部 consumer はこれらを公開契約として扱ってはいけません。
公開契約は、以下に定義する CLI response JSON です。

## JSON Envelope

CLI の各成功実行は、`stdout` に次の envelope を持つ JSON object をちょうど 1 つ書きます。

```json
{
  "ok": true,
  "result": "success",
  "data": null,
  "error": null
}
```

envelope field は安定しています。

- `ok`
  - Boolean。成功した domain outcome のときだけ `true`
- `result`
  - 安定した機械可読 result code
- `data`
  - `null` または command 固有 JSON object
- `error`
  - 成功時は `null`
  - invalid request や runtime failure 時は `{"message":"..."}`

engine は次の区別を意図的に保ちます。

- `duplicate`、`wrong_password`、`locked_out` のような domain failure は、
  CLI 実行としては有効である
- state load failure のような runtime failure は engine failure である

この区別は `ok` field と process exit code の両方に反映されます。

## 終了コード

engine は [`engine/include/cli/exit_codes.h`](../engine/include/cli/exit_codes.h) で
次の stable process exit code を公開します。

- `0`
  - JSON body の `ok` が `false` であっても、command execution 自体は完了
- `1`
  - path construction failure、persistence load/save failure、audit append failure などの runtime failure
- `2`
  - unknown command、unknown option、required argument 欠落などの invalid CLI request

この方針により client は次を区別できます。

- transport/runtime failure
- request-shape failure
- domain-level authentication outcome

## コマンド結果

### `register`

必須 option:

- `--login-id`
- `--password`

安定した `result` code:

- `success`
- `duplicate`
- `system_error`
- `invalid_request`

`success` と `duplicate` はどちらも `data: null` を返します。

成功出力例:

```json
{"ok":true,"result":"success","data":null,"error":null}
```

参照用 golden 出力:

- [`tests/golden/cli-json/register-success.json`](../tests/golden/cli-json/register-success.json)
- [`tests/golden/cli-json/register-duplicate.json`](../tests/golden/cli-json/register-duplicate.json)

### `login`

必須 option:

- `--login-id`
- `--password`

安定した `result` code:

- `success`
- `unknown_user`
- `locked_out`
- `wrong_password`
- `already_authenticated`
- `system_error`
- `invalid_request`

成功時も失敗時も `data: null` を返します。

参照用 golden 出力:

- [`tests/golden/cli-json/login-success.json`](../tests/golden/cli-json/login-success.json)
- [`tests/golden/cli-json/login-unknown-user.json`](../tests/golden/cli-json/login-unknown-user.json)
- [`tests/golden/cli-json/login-wrong-password.json`](../tests/golden/cli-json/login-wrong-password.json)
- [`tests/golden/cli-json/login-locked-out.json`](../tests/golden/cli-json/login-locked-out.json)
- [`tests/golden/cli-json/login-already-authenticated.json`](../tests/golden/cli-json/login-already-authenticated.json)

### `change-password`

必須 option:

- `--old-password`
- `--new-password`

安定した `result` code:

- `success`
- `unauthorized`
- `wrong_password`
- `system_error`
- `invalid_request`

すべての応答で `data: null` を返します。

参照用 golden 出力:

- [`tests/golden/cli-json/change-password-success.json`](../tests/golden/cli-json/change-password-success.json)
- [`tests/golden/cli-json/change-password-unauthorized.json`](../tests/golden/cli-json/change-password-unauthorized.json)

### `logout`

必須 option:

- なし

安定した `result` code:

- `success`
- `system_error`
- `invalid_request`

正常完了時は `data: null` を返します。

### `show-audit`

必須 option:

- なし

安定した `result` code:

- `success`
- `system_error`
- `invalid_request`

`data` の形:

```json
{
  "events": [
    {
      "timestamp": "2026-01-01T00:00:00Z",
      "event_type": "Register",
      "login_id": "alice",
      "result": "success"
    }
  ]
}
```

安定した event field:

- `timestamp`
  - engine が生成する UTC ISO-8601 timestamp
- `event_type`
  - `Register`, `LoginSuccess`, `LoginFailure`, `Lock`, `PasswordChange`, `Logout` のいずれか
- `login_id`
  - event に対応する login identifier
- `result`
  - event に記録された安定した機械可読 result code

参照 sample:

- [`observability/audit/sample-events.json`](../observability/audit/sample-events.json)

### `show-metrics`

必須 option:

- なし

安定した `result` code:

- `success`
- `system_error`
- `invalid_request`

`data` の形:

```json
{
  "login_success_count": 1,
  "login_failure_count": 2,
  "lockout_count": 1
}
```

安定した metric field:

- `login_success_count`
- `login_failure_count`
- `lockout_count`

参照 sample:

- [`observability/metrics/sample-metrics.json`](../observability/metrics/sample-metrics.json)

## Domain Failure と Runtime Failure

この区別は契約の核心です。

Domain failure は:

- 依然として有効な JSON を返し
- exit code `0` のままで
- `ok = false` と安定した `result` によって認証 outcome を伝えます

Runtime failure は:

- それでも JSON を返すが
- exit code `1` を返し
- `result = "system_error"` または `result = "invalid_request"` を使って、
  それが operational failure か request-shape failure かを表します

## 契約の利用者

現在意図している consumer は次です。

- [`tui/`](../tui/) 配下の Go Bubble Tea TUI
- 将来の読み取り専用 analysis / reporting helper
- [`tests/`](../tests/) 配下の contract test と golden test

これらの consumer は次に依存してよいです。

- command 名
- 安定した option 名
- JSON field 名
- 安定した `result` code
- exit-code policy

逆に、次には依存してはいけません。

- 公開 API としての `users.tsv`, `session.txt`, `audit.log` file format
- engine 内部 struct layout
- engine 内部 helper function 名
