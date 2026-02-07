<?php

$wochentage = [
    "Montag" => "Mo",
    "Dienstag" => "Di",
    "Mittwoch" => "Mi",
    "Donnerstag" => "Do",
    "Freitag" => "Fr",
    "Samstag" => "Sa",
    "Sonntag" => "So"
];


foreach ($wochentage as $tag => $abkuerzung) {
    echo $tag . ": " . $abkuerzung . " <br> ";
}

?>