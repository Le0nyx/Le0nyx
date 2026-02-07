<?php
// http://localhost:8000/p01_notizbuch.php?user=Leon

//logout
if (isset($_GET['logout'])) {
    setcookie('user', '', time() - 3600);
    header("Location: p01_notizbuch.php");
    exit;
}

//first login
if (isset($_COOKIE['user'])) {
    $user = $_COOKIE['user'];
} elseif (isset($_GET['user'])) {
    $user = $_GET['user'];
    setcookie('user', $user, time() + 3600 * 24 * 30);
} else {
    echo "Kein username";
    exit;
}

$noteCookie = "note_" . $user;
$timeCookie = "time_" . $user;

$note = "";

if (isset($_POST['note'])) {
    setcookie($noteCookie, $_POST['note'], time() + 3600 * 24 * 30);
    setcookie($timeCookie, time(), time() + 3600 * 24 * 30);
    $note = $_POST['note'];
} elseif (isset($_COOKIE[$noteCookie])) {
    $note = $_COOKIE[$noteCookie];
}

$lastChange = "never";
if (isset($_COOKIE[$timeCookie])) {
    $lastChange = date("d.m.Y H:i:s", $_COOKIE[$timeCookie]);
}
?>

Letzte Änderung: <?php echo $lastChange . " von " . $user; ?>

<form method="post">
    <textarea name="note"><?php echo htmlspecialchars($note); ?></textarea><br><br>
    <button type="submit">Speichern</button>
</form>

<form method="get">
    <button name="logout" value="1">Logout</button>
</form>
