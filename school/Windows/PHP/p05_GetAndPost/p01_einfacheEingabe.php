<!DOCTYPE html>
<html lang="de">
<head>
    <title>Einfache Eingabe</title>
</head>
<body>
    <h1>Namenseingabe</h1>
    
    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        // Zielseite: Begrüßung anzeigen
        $name = htmlspecialchars($_POST['name'] ?? '');
        echo "<h2>Hallo, $name! Willkommen auf unserer Seite.</h2>";
        echo '<p><a href="' . $_SERVER['PHP_SELF'] . '">Zurück zum Formular</a></p>';
    } else {
       
        ?>
        <form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
            <label for="name">Ihr Name:</label><br>
            <input type="text" id="name" name="name" required><br><br>
            <button type="submit">Absenden</button>
        </form>
        <?php
    }
    ?>
</body>
</html>