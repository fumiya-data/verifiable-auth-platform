# ADR 0004: 分析とレポート層に Python を採用する

この文書は [`../../docs/adr/0004-python-analysis-and-reporting.md`](../../docs/adr/0004-python-analysis-and-reporting.md) の日本語版です。

## ステータス

承認済み

## コンテキスト

分析層は、監査データの集計、結果の可視化、観測成果物からのレポート生成を担当します。
この層は意図的に読み取り専用です。将来的にはdatabase-backed workflowに拡張されることを
想定し、実用的に統合できる形をこの層に持たせることが必要です。

## 決定

分析・レポート層には `Python` を採用します。

## 根拠

- Python は、レポート、可視化、データ指向ワークフローに強く適しています。
- 将来の database 統合や downstream analysis pipeline に向けた実用的な道筋を提供します。
- 可視化とレポート生成は、Python が成熟した productive ecosystem を持つ領域です。
- そのため、監査ログやメトリクスを読みやすい分析出力へ変換する言語として自然です。

## 帰結

- 分析層は、engine や TUI の変更を強いずに、より豊かなレポートやデータ統合へ拡張できます。
- プロジェクトは、集計、チャート生成、レポート生成に関する既存の Python tooling の恩恵を受けます。
- 分析が system logic の第二実装にならないよう、読み取り専用境界を明示的に保ち続けることが重要です。
