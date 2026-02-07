<?php
// Formular mit Name und E-Mail Feldern mit Validierung

$errors = [];
$name = '';
$email = '';
$success = false;

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Name validieren
    if (empty($_POST['name'])) {
        $errors[] = 'Name muss ausgefüllt sein.';
    } else {
        $name = htmlspecialchars(trim($_POST['name']));
    }
    
    // E-Mail validieren
    if (empty($_POST['email'])) {
        $errors[] = 'E-Mail muss ausgefüllt sein.';
    } else {
        $email = trim($_POST['email']);
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors[] = 'E-Mail ist nicht gültig.';
        } else {
            $email = htmlspecialchars($email);
        }
    }
    
    // Wenn keine Fehler, Erfolg
    if (empty($errors)) {
        $success = true;
    }
}
?>

<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Name und E-Mail Formular</title>
    <style>
        .error { color: red; }
        .success { color: green; }
    </style>
</head>
<body>
    <h1>Name und E-Mail Formular</h1>
    
    <?php if (!empty($errors)): ?>
        <div class="error">
            <ul>
                <?php foreach ($errors as $error): ?>
                    <li><?php echo $error; ?></li>
                <?php endforeach; ?>
            </ul>
        </div>
    <?php endif; ?>
    
    <?php if ($success): ?>
        <div class="success">
            <p>Erfolgreich gesendet!</p>
            <p><strong>Name:</strong> <?php echo $name; ?></p>
            <p><strong>E-Mail:</strong> <?php echo $email; ?></p>
        </div>
    <?php endif; ?>
    
    <form method="POST" action="">
        <div>
            <label for="name">Name:</label><br>
            <input type="text" id="name" name="name" value="<?php echo $name; ?>">
        </div>
        <br>
        <div>
            <label for="email">E-Mail:</label><br>
            <input type="text" id="email" name="email" value="<?php echo $email; ?>">
        </div>
        <br>
        <button type="submit">Absenden</button>
    </form>
</body>
</html>