# tiny_algorithm_cpp

組み込み用のメモリアロケーションを行わないことを前提としたライブラリ群である．
全てヘッダファイル上で完結しているので，実際に使用する際には`rm ./**/*.cpp`を事前に実行しておくことを推奨する.

これは前回，私がマイクロマウスを制作する際にC++標準ライブラリが使用できなかったことを反省して開発されたものである．

- `toys.hpp`: `max()`など，コンテナではない細々とした関数が含まれている．
- `priority_deque.hpp`: 優先度つき双方向取り出しキューコンテナ．これはA*探索を最小メモリで実装する際に必要となったものである．
- `stuck.hpp`: スタックコンテナ．再帰関数などが実装できない場合に通常のループで代替するために必要となったものである．

# Gxx Environment with Docker (Docker Compose) & VSCode
- GCC/G++
- GDB

## How to run?
Open `gcc-compiler` directory as root directory in vscode. If VSCode find the Dev Container configuration file, It call with notification ask you to reopen folder to develop in a container `Folder contains a Dev Container configuration file. Reopen folder to develop in a container.` Select `Reopen in Container`!
