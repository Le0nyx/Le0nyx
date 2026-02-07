<?php
    if (isset($_POST['a']) && isset($_POST['b']) && $_POST['a'] && $_POST['b']) {
        $a = (int)$_POST['a'];
        $b = (int)$_POST['b'];
        
        function ggt($x, $y) {
            while ($y != 0) {
                $temp = $x % $y;
                $x = $y;
                $y = $temp;
            }
            return $x;
        }
        
        $lcm = ($a * $b) / ggt($a, $b);
        echo "kgV of $a and $b: $lcm";
    }
?>

<form method="POST">
    <input type="number" name="a" placeholder="First number" required>
    <input type="number" name="b" placeholder="Second number" required>
    <input type="submit" value="Calculate">
</form>
