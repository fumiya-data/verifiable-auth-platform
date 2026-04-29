# Verifiable Auth Platform

この文書は [`README.md`](./README.md) の日本語版です。

Verifiable Auth Platform は、仕様、実装、テスト、観測可能性の全体にわたる
検証可能性を中心に据えたローカル認証基盤です。

## プロジェクト状況

このリポジトリは現在開発中であり、完成した製品や本番利用可能な認証システムとして
扱わないでください。現時点の主目的は、仕様、C エンジン、Go TUI、テスト、
観測可能性の成果物が、検証可能な形で互いに整合している状態を作ることです。

現在の進捗は次のとおりです。

- Lean 仕様と状態機械の文書で、意図する認証挙動を定義しています。
- C エンジンはローカル認証フローを実装し、JSON CLI 契約を公開しています。
- Go Bubble Tea TUI はエンジン CLI の運用ラッパーであり、認証ルールを別実装しません。
- 契約ノート、golden 出力、E2E runbook、fixture 整合性確認を用意し、
  各レイヤを揃えるための検証材料にしています。
- 分析と観測可能性のディレクトリにはサンプルデータとレポート補助ツールがありますが、
  完成した監視製品ではなく、現時点では支援成果物です。

開発が進むにつれて、インターフェース、文書、検証範囲は今後も変わる可能性があります。

## ドキュメント

- [ドキュメント索引](./docs-jp/README-日本語.md)
- [システム仕様書](./docs-jp/仕様書.md)
- [Lean 仕様と C エンジンの対照表](./docs-jp/Lean仕様とC言語エンジンの対照表.md)
- [仕様・Lean・エンジンの整合状況](./docs-jp/仕様・Lean・C言語の整合性検討.md)
- [エンジン CLI 契約](./docs-jp/エンジン用CLI.md)
- [Go TUI 運用 Runbook](./docs-jp/Go-TUI運用Runbook.md)
- [認証状態機械](./docs-jp/認証状態機械.md)

## アーキテクチャ決定記録

- [ADR 0001: 形式仕様層に Lean を採用する](./docs-jp/adr/0001-形式仕様言語としてLeanを採用.md)
- [ADR 0002: エンジン実装層に C を採用する](./docs-jp/adr/0002-エンジン実装言語としてCを採用.md)
- [ADR 0003: Go TUI を薄い運用ラッパーとして保つ](./docs-jp/adr/0003-TUIの薄い運用ラッパーとしてGoを採用.md)
- [ADR 0004: 分析とレポート層に Python を採用する](./docs-jp/adr/0004-分析とレポート層にPythonを採用.md)

## 前提環境

- `elan` 経由の Lean 4
  - 正確なツールチェインは [`spec/lean-toolchain`](./spec/lean-toolchain) に固定されています。
- エンジン用の C ツールチェイン
  - `cmake` + `ctest` が推奨の検証経路です。
  - 利用可能な環境では `make` が代替手段です。
  - 選択したビルド系に対して `gcc` または `clang` が必要です。
- TUI 用の Go
  - 対象バージョンは [`tui/go.mod`](./tui/go.mod) に固定されています。
- 分析層用の Python 3.12
  - 分析スクリプト実行前に [`analysis/requirements.txt`](./analysis/requirements.txt) から依存を入れてください。

## 検証

リポジトリ全体の検証入口は次のとおりです。

- `scripts/run-spec-check.sh`
  - `spec/` 配下の Lean 参照モデルをビルドします。
- `scripts/run-spec-check.ps1`
  - Windows 上で同じ Lean ビルドを行う PowerShell 版です。
- `scripts/run-engine-tests.sh`
  - C エンジンをソースからビルドし、テストします。
- `scripts/run-engine-tests.ps1`
  - Windows 上でエンジン検証を行う PowerShell 版です。
- `scripts/run-tui.sh`
  - Bubble Tea TUI を起動します。
- `scripts/run-tui.ps1`
  - Windows 上で Bubble Tea TUI を起動する PowerShell 版です。
- `scripts/run-e2e.sh`
  - 仕様、エンジン、TUI テスト、fixture 整合性確認をまとめて実行します。
- `scripts/run-e2e.ps1`
  - 同じエンドツーエンド検証を行う PowerShell 版です。

Python の分析層は個別に次でも確認できます。

- `python analysis/scripts/check_fixture_consistency.py`
- `python analysis/scripts/summarize_audit.py observability/audit/sample-events.json`
- `python analysis/scripts/summarize_metrics.py observability/metrics/sample-metrics.json`
- `python analysis/scripts/export_report.py --audit observability/audit/sample-events.json --metrics observability/metrics/sample-metrics.json --report both`

## リポジトリ構成

- `spec/`
  - Lean の状態機械と refinement note 群です。
- `engine/`
  - C 認証エンジン、CLI 契約、永続化アダプタです。
- `tui/`
  - エンジン CLI の上に載る Go Bubble Tea の運用ラッパーです。
- `observability/`
  - 監査ログとメトリクスの契約定義です。
- `analysis/`
  - 読み取り専用の Python 集計・レポート基盤です。
- `tests/`
  - 契約ノート、golden 出力、E2E runbook 群です。
- `fixtures/`
  - 正規のサンプル状態とシナリオ成果物です。
- `.github/workflows/`
  - spec、engine、TUI、end-to-end を検証する GitHub Actions の入口です。
