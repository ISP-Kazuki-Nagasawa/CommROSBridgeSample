CommROSBridgeSample
-----------------------
ROSBridge を経由して ROS topic と UE4 とのやり取りを行うサンプルです。  
ROSBridge との通信は ROS Integration (https://github.com/code-iai/ROSIntegration) を使用しています。

詳しくは技ラボの記事を参照してください。


### プラグイン
本リポジトリでは ROS Integration を利用しています。  
使用の際は、git clone 後、submodule を更新してください。
```
git clone <this repository>
git submodule init
git submodule update
```


### 実行方法 (概要)
1. ROSBridge TCP 起動
2. UE4側起動


※ ROSBridge が起動していないと落ちます。

