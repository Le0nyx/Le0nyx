<?php
    $zahl = rand(0, 100);
    $binaer = decbin($zahl);
    
    $ausgabe = $zahl . " = " . $binaer . PHP_EOL;
    $dateiname = "p04_binaer_rechnungen.txt";
    file_put_contents($dateiname, $ausgabe, FILE_APPEND);
    
    echo "Berechnung durchgeführt: " . $ausgabe;
    echo "Ergebnis wurde in '{$dateiname}' gespeichert.";
?>
