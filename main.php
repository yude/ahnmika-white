<?php 

// # Important Notice
// pcntl_signal 関数は、Windows では実行できません。
// その他の OS に PHP をインストールして、ご利用ください。

// 魔法の言葉
pcntl_async_signals(true);

// SIGUSR1 を無視
pcntl_signal(SIGUSR1, SIG_IGN);

//SIGINT のシグナルハンドラ設定
$terminate = false;

pcntl_signal(
    SIGINT,
    function ($signo, $siginfo) use (&$terminate) {
        $terminate = true;
    }
);

While(True){

    $i = $i + 1;
    $value = mt_rand(100,1000);
    echo "白って${value}色あんねん\n";

    if ($terminate) {
        echo "${i}人のアンミカ\n";
        exit();
    };

};

?>