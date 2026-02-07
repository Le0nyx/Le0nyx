<?php
    $zahl1 = $_GET['zahl1'] ?? '';
    $zahl2 = $_GET['zahl2'] ?? '';
    $selectedOp = $_GET['operation'] ?? '';
    $printMode = $_GET['printMode'] ?? '';
    
    $operations = ['addition' => '+', 'subtraction' => '-', 'multiplication' => '*', 'division' => '/'];
    
    $result = '';
    if ($zahl1 !== '' && $zahl2 !== '' && $selectedOp !== '') {
        switch($selectedOp) {
            case 'addition': $result = $zahl1 + $zahl2; break;
            case 'subtraction': $result = $zahl1 - $zahl2; break;
            case 'multiplication': $result = $zahl1 * $zahl2; break;
            case 'division': $result = ($zahl2 != 0) ? $zahl1 / $zahl2 : 'Division durch 0 nicht möglich'; break;
        }
        if ($result !== '') {
            file_put_contents('p02_calculator.txt', "$zahl1 {$operations[$selectedOp]} $zahl2 = $result\n", FILE_APPEND);
        }
    }

    echo "<!DOCTYPE html><html><head><title>Calculator</title></head><body>";
    echo "<form method='GET'>";
    echo "Zahl 1: <input type='number' name='zahl1' value='" . htmlspecialchars($zahl1) . "'><br><br>";
    echo "Zahl 2: <input type='number' name='zahl2' value='" . htmlspecialchars($zahl2) . "'><br><br>";
    echo "Operation:<br>";
    
    foreach($operations as $key => $symbol) {
        $checked = ($selectedOp === $key) ? 'checked' : '';
        echo "<input type='radio' name='operation' value='$key' $checked>" . ucfirst($key) . " ($symbol)<br>";
    }
    
    echo "<br>Print Mode:<br>";
    echo "<input type='radio' name='printMode' value='current' " . ($printMode === 'current' ? 'checked' : '') . ">Print Current<br>";
    echo "<input type='radio' name='printMode' value='all' " . ($printMode === 'all' ? 'checked' : '') . ">Print All<br>";
    
    echo "<br><input type='submit' value='Absenden'></form>";
    
    if ($printMode === 'current' && $result !== '') {
        echo "<h3>Ergebnis: " . htmlspecialchars($result) . "</h3>";
    } elseif ($printMode === 'all' && file_exists('p02_calculator.txt')) {
        echo "<h3>All Calculations:</h3>";
        echo "<pre>" . htmlspecialchars(file_get_contents('p02_calculator.txt')) . "</pre>";
    }
    
    echo "</body></html>";
?>
