<?php
function fibonacci($n) {
    if ($n <= 0) return [];
    if ($n == 1) return [0];
    if ($n == 2) return [0, 1];
    
    $fib = [0, 1];
    
    for ($i = 2; $i < $n; $i++) {
        $fib[$i] = $fib[$i - 1] + $fib[$i - 2];
    }
    
    return $fib;
}


$anzahl = 10;
$fibonacci_reihe = fibonacci($anzahl);

echo "Fibonacci-Reihe bis zur " . $anzahl . ". Stelle:\n";
echo implode(" ", $fibonacci_reihe) . "\n";
?>