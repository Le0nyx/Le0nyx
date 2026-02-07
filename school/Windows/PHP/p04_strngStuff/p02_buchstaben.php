<?php
$username = "Max.Mustermann";
$password = "Mein Super Passwort!";

echo "Benutzername- und Passwort-Überprüfung\n\n";

if (strpos($username, ".") === false && strpos($username, "@") === false) {
    echo "Warnung: Benutzername enthält weder '.' noch '@'!\n";
} else {
    echo "Benutzername enthält '.' oder '@'\n";
}

if (strlen($password) < 8) {
    echo "Fehler: Passwort muss mindestens 8 Zeichen lang sein!\n";
} else {
    echo "Passwort hat ausreichende Länge (" . strlen($password) . " Zeichen)\n";
}

$modifiedPassword = str_replace(" ", "_", $password);
echo "\nModifiziertes Passwort: $modifiedPassword\n";

$kuerzel = substr($username, 0, 3);
echo "Kürzel: $kuerzel\n";

$loginToken = $kuerzel . "_" . $modifiedPassword;
echo "Login-Token: $loginToken\n";

$loginTokenLowercase = strtolower($loginToken);
echo "Login-Token (Kleinbuchstaben): $loginTokenLowercase\n";

?>
