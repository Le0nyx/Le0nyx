<?php
    // Definiere den Maximalwert an Benutzern
    $maxBenutzer = 100;

    // Simuliere die aktuelle Nutzerzahl mit einer Zufallszahl
    $aktuelleNutzerzahl = rand(1, 150);

    // Prüfe ob das Maximum überschritten wird
    if ($aktuelleNutzerzahl > $maxBenutzer) {
        print("Fehler: Maximum von $maxBenutzer Benutzern überschritten!");
        exit();
    } else {
        print("Aktuelle Nutzerzahl: $aktuelleNutzerzahl");
    }

?>