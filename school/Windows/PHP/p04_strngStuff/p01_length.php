<?php
$text = "PHP ist eine weit verbreitete Skriptsprache.";

echo "<h2>Original Text:</h2>";
echo $text . "<br><br>";

echo "<h3>1. Länge des Textes:</h3>";
echo strlen($text) . " Zeichen<br><br>";

echo "<h3>2. Text in Großbuchstaben:</h3>";
echo strtoupper($text) . "<br><br>";

echo "<h3>3. Text in Kleinbuchstaben:</h3>";
echo strtolower($text) . "<br><br>";

echo "<h3>4. Erste 5 Zeichen:</h3>";
echo substr($text, 0, 5) . "<br><br>";

echo "<h3>5. Position von 'PHP':</h3>";
$position = strpos($text, "PHP");
echo "Position: " . $position . "<br><br>";

echo "<h3>6. Text mit Ersetzung:</h3>";
echo str_replace("PHP", "Hypertext Preprocessor", $text) . "<br>";


?>