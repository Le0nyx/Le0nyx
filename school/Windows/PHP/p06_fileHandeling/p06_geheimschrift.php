
<?php
$geheimcode = [
    'Montag' => 'Baumhaus',
    'Dienstag' => 'Ventilator',
    'Mittwoch' => 'Unterricht',
    'Donnerstag' => 'Behördenwegweiser',
    'Freitag' => 'Fahrradschloss',
    'Samstag' => 'Kettenschaltung',
    'Sonntag' => 'Montag',
    'Wirtschaftsinformatik' => 'Freude',
    'Deutsch' => 'Brezeln',
    'Mathematik' => 'Kaugummi'
];

$text_decrypt = "Letzten Behördenwegweiser hatten wir Kaugummi, das war anstrengend. Zum Glück blieb dann nur noch der Fahrradschloss. Kettenschaltung und Montag konnte ich mich nicht richtig entspannen, denn Baumhaus erwartet uns schon wieder Freude. Naja ... besser als Brezeln.";
$text_encrypt = "Am Freitag haben wir Mathematik, am Dienstag ebenfalls. Mein Lieblingsfach ist Deutsch, das wir leider nur am Mittwoch haben. Am meisten";

if (isset($_POST['text_decrypt'])) {
    $text_decrypt = $_POST['text_decrypt'];
}
if (isset($_POST['text_encrypt'])) {
    $text_encrypt = $_POST['text_encrypt'];
}


$entschluesselt = strtr($text_decrypt, array_flip($geheimcode));

$verschluesselt = strtr($text_encrypt, $geheimcode);
?>

<form method="post">
    Entschlüsseln: <input type="text" name="text_decrypt" value="<?= htmlspecialchars($text_decrypt) ?>"><br>
    Verschlüsseln: <input type="text" name="text_encrypt" value="<?= htmlspecialchars($text_encrypt) ?>"><br>
    <input type="submit" value="Senden">
</form>

Entschlüsselt: <?=$entschluesselt?> <br><br>
Verschlüsselt: <?=$verschluesselt?>


