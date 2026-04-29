# Go TUI 運用 Runbook

この runbook は、Verifiable Auth Platform の Go Bubble Tea TUI をビルドし、
起動し、簡単に確認し、拡張するときの手順をまとめたものです。

## 範囲

`tui/` 配下の TUI は、C エンジン CLI の薄い運用ラッパーです。TUI 側では
認証ルールを実装しません。認証挙動は [`エンジン用CLI.md`](./エンジン用CLI.md)
で定義された安定した CLI / JSON 契約を通して扱います。

## 前提環境

- [`tui/go.mod`](../tui/go.mod) と互換性のある Go。
- エンジン CLI をビルドできる C ツールチェイン。
- `cmake` と Ninja などのビルドバックエンド。

Windows では、MSYS2 UCRT GCC を使う経路が最も扱いやすい想定です。

```powershell
Get-Command gcc,cmake,ninja
```

## エンジン CLI をビルドする

TUI は `engine_cli` 実行ファイルを必要とします。明示的な指定がない場合、
次のリポジトリ相対パスを探します。

- `engine/.build/engine_cli.exe`
- `engine/.build/engine_cli`
- `engine/build/engine_cli.exe`
- `engine/build/engine_cli`

### PowerShell

```powershell
cmake -S engine -B engine\build -G Ninja -DCMAKE_C_COMPILER=C:/msys64/ucrt64/bin/gcc.exe
cmake --build engine\build --target engine_cli
```

別のコンパイラ設定で正しくビルドできる場合は、`-DCMAKE_C_COMPILER=...` を省略できます。

### Bash

```bash
cmake -S engine -B engine/build
cmake --build engine/build --target engine_cli
```

## TUI を起動する

### PowerShell

```powershell
.\scripts\run-tui.ps1 --data-dir .\.engine-data
```

### Bash

```bash
./scripts/run-tui.sh --data-dir ./.engine-data
```

エンジンバイナリが既定の場所にない場合は、明示的に渡します。

```powershell
.\scripts\run-tui.ps1 --engine-path .\engine\build\engine_cli.exe --data-dir .\.engine-data
```

環境変数でも指定できます。

```powershell
$env:VERIFIABLE_AUTH_ENGINE_PATH = "C:\path\to\engine_cli.exe"
$env:VERIFIABLE_AUTH_DATA_DIR = "C:\path\to\data-dir"
.\scripts\run-tui.ps1
```

## 操作

```text
Up/Down または j/k  ホーム画面の選択を移動
Enter               操作を選択、またはフォームを送信
Esc                 ホーム画面に戻る
r                   監査ログまたはメトリクス画面を再読み込み
q                   ホーム、監査ログ、メトリクス画面から終了
Ctrl+C              どの画面からでも終了
```

## スモークテスト

1. TUI を起動します。
2. `Register` を選択します。
3. 新しい `login_id` とパスワードを入力します。
4. ステータスバーが `register -> success` を表示することを確認します。
5. 同じ認証情報で `Login` を選択します。
6. ステータスバーが `login -> success` を表示することを確認します。
7. `Show Audit` を選択し、register / login イベントが見えることを確認します。
8. `Show Metrics` を選択し、ログインカウンタが期待どおり変わっていることを確認します。

フロー別の確認観点は [`tests/e2e`](../tests/e2e) 配下の runbook を参照してください。

## Go TUI を検証する

エンジンとは別に、TUI パッケージのテストを実行できます。

```powershell
Push-Location tui
go test ./...
Pop-Location
```

## トラブルシュート

`engine binary not found`

`engine_cli` を `engine/.build` または `engine/build` にビルドするか、
TUI 起動時に `--engine-path` を渡してください。

`decode engine response`

エンジンコマンドを直接実行し、stdout に JSON オブジェクトが 1 つだけ出力されることを
確認してください。TUI は `エンジン用CLI.md` の JSON envelope に依存します。

Windows Clang が CRT deprecation warning で失敗する

上記の MSYS2 UCRT GCC 経路を使うか、MSVC CRT deprecation warning をビルド失敗に
しないコンパイラ設定を使ってください。

ローカル認証状態が古い

指定した `--data-dir` には、エンジン管理の `users.tsv`、`session.txt`、`audit.log`
が保存されます。きれいなフローを試す場合は、新しいデータディレクトリを使ってください。

## 拡張点

TUI に新しい操作を追加するときは、主に次のファイルを更新します。

- `docs/engine-cli-contract.md`
  - まず公開エンジンコマンドを定義または更新します。
- `tui/internal/engineclient/`
  - クライアントメソッドとレスポンスの decode 形を追加します。
- `tui/internal/commands/`
  - クライアント呼び出しを Bubble Tea command として包みます。
- `tui/internal/messages/`
  - update loop に返す完了メッセージを追加します。
- `tui/internal/types/types.go`
  - 画面が必要な操作では route や selection の値を追加します。
- `tui/internal/screens/`
  - 画面モデルと view を追加または更新します。
- `tui/internal/app/update.go`
  - キー処理、非同期 command の起動、完了処理を配線します。
- `tui/internal/app/view.go`
  - 新しい route を描画します。

入力の収集、エンジン呼び出し、結果表示が TUI の責務です。検証や認証判断は
C エンジン側に置き、CLI 契約を保ってください。
