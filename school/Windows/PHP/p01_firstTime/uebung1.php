<?php
// Definiere die Konstante PI
define('PI', 3.14159);

// Deklariere Variable R für den Radius (Zufallszahl zwischen 1 und 10)
$r = rand(1, 10);

// Berechne Umfang und Flächeninhalt
$umfang = 2 * PI * $r;
$flaeche = PI * $r * $r;

// Ausgabe der Ergebnisse
echo "Radius: " . $r . "<br>";
echo "Umfang: " . $umfang . "<br>";
echo "Flächeninhalt: " . $flaeche . "<br><br>";

// Überprüfung mit isset()
echo "isset(\$r): " . (isset($r) ? 'true' : 'false') . "<br>";
echo "isset(\$umfang): " . (isset($umfang) ? 'true' : 'false') . "<br>";
echo "isset(\$flaeche): " . (isset($flaeche) ? 'true' : 'false') . "<br><br>";

// Überprüfung mit var_dump()
echo "var_dump(\$r): ";
var_dump($r);
echo "<br>";

echo "var_dump(\$umfang): ";
var_dump($umfang);
echo "<br>";

echo "var_dump(\$flaeche): ";
var_dump($flaeche);
echo "<br>";

echo "var_dump(PI): ";
var_dump(PI);

?>

