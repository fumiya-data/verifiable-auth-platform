# 仕様・Lean・エンジンの整合状況

この文書は [`../docs/spec-engine-alignment.md`](../docs/spec-engine-alignment.md) の日本語版です。

この文書は、次の 3 層の現在の整合状況を記録します。

- [`docs/system-specification.md`](../docs/system-specification.md)
- [`spec/VerifiableAuth`](../spec/VerifiableAuth)
- [`engine/include`](../engine/include) と [`engine/src`](../engine/src)

## 現在の状況

3 層は現在、次の中核挙動について整合しています。

- 状態モデル: `users + authenticated session`
- Lean の名目的な `LoginId` / `Password` wrapper は、engine 境界では C の文字列値へ refinement される
- Lean の nested `Credential` model は、C engine の flat な `salt` / `password_hash` user field へ refinement される
- 操作集合: `register`, `login`, `change_password`, `logout`
- CLI 契約で公開される result code
- ロックアウト閾値挙動と session 保持規則
- salt と hash の両方を置換するパスワード変更意味論
- 4 つの core operation すべてに対する Lean の `CoreInvariants` preservation
- 監査イベントと導出メトリクスの observability mapping
- `already_authenticated` を `LoginFailure` として記録しつつ、`login_failure_count` は増やさないという規則

## 確認対象

### 文書仕様

- [`仕様書.md`](./仕様書.md)

### Lean モデル

- [`spec/VerifiableAuth/RegisterSpec.lean`](../spec/VerifiableAuth/RegisterSpec.lean)
- [`spec/VerifiableAuth/LoginSpec.lean`](../spec/VerifiableAuth/LoginSpec.lean)
- [`spec/VerifiableAuth/ChangePasswordSpec.lean`](../spec/VerifiableAuth/ChangePasswordSpec.lean)
- [`spec/VerifiableAuth/LogoutSpec.lean`](../spec/VerifiableAuth/LogoutSpec.lean)
- [`spec/VerifiableAuth/WellFormed.lean`](../spec/VerifiableAuth/WellFormed.lean)
- [`spec/VerifiableAuth/GlobalInvariants.lean`](../spec/VerifiableAuth/GlobalInvariants.lean)
- [`spec/VerifiableAuth/RefinementNotes.lean`](../spec/VerifiableAuth/RefinementNotes.lean)

### C エンジン

- [`engine/src/core`](../engine/src/core) 配下の中核状態遷移
- [`engine/src/cli/command_runner.c`](../engine/src/cli/command_runner.c) にある CLI 契約
- [`engine/src/storage`](../engine/src/storage) にある監査・メトリクス永続化

## 実施済み検証

- `spec/` における `lake build` が成功
- Windows 上で `scripts/run-engine-tests.ps1` が成功し、CTest は 17/17 件成功
- リポジトリには
  [`../scripts/run-engine-tests.sh`](../scripts/run-engine-tests.sh) による
  正規の engine 検証経路が定義済み
  - fresh な CMake build を構成し
  - C エンジンをコンパイルし
  - CTest を実行する
- 契約対応と golden 対応は [`tests/contract`](../tests/contract) および
  [`tests/golden`](../tests/golden) に記録済み

## 意図的なモデリング差異

3 層は意味論的には整合していますが、すべての詳細を同じ抽象度で
記述しているわけではありません。

- Lean は salt と password hash を記号的にモデル化する
  - engine はユーザーごとのランダム salt と `PBKDF2-HMAC-SHA256` を使う
  - Lean は crypto internals を再現せずに状態遷移を議論するために、
    記号的な `Salt.rotate` と `derivePasswordHash` を用いる
- Lean は storage file format や timestamp をモデル化しない
  - engine は具体的な file-backed store と UTC 監査 timestamp を持つ
- 文書仕様は挙動に対して規範的であり、Lean と C はその実行可能 refinement である

## 今後の更新規則

将来の変更が次のいずれかに触れる場合、3 層を一緒に更新すること。

- operation branch または result code
- invariant または well-formedness rule
- audit event mapping
- metrics counting rule
- CLI JSON field 名または command 名

同じ変更では、[`../observability`](../observability) と
[`../analysis`](../analysis) にある observability / analysis 契約も更新すること。
