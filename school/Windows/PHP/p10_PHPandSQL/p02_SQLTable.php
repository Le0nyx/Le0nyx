<?php
    require_once 'SECRET.php';
    $mysqli = new mysqli($host, $user, $pass, "STASTLEO_DB1");
    
    if (isset($_POST['search'])) { $id = $_POST['search'];} 
    else { $id = 'G001'; }

    // Prepared statement to prevent SQL injection
    $sql = "SELECT anr, mwst, bezeichnung, listenpreis, bestand, mindestbestand, verpackung, lagerplatz FROM artikel WHERE anr=?";

    $stmt = $mysqli->prepare($sql);

    $stmt->bind_param("s", $id);
    $stmt->execute();


    $result = $stmt->get_result();
?>

<html>
<body>
    <?php
        echo "<br> Gesamt: " . $result->num_rows . "<br><br><br>";

        echo "<table border='1'>";
        echo "<tr>";
        echo "<th>Artikel-Nr.</th>";
        echo "<th>MwSt</th>";
        echo "<th>Bezeichnung</th>";
        echo "<th>Listenpreis (€)</th>";
        echo "<th>Bestand</th>";
        echo "<th>Mindestbestand</th>";
        echo "<th>Verpackung</th>";
        echo "<th>Lagerplatz</th>";
        echo "</tr>";
        
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['anr'] . "</td>";
            echo "<td>" . $row['mwst'] . "</td>";
            echo "<td>" . $row['bezeichnung'] . "</td>";
            echo "<td>" . $row['listenpreis'] . " €</td>";
            echo "<td>" . $row['bestand'] . "</td>";
            echo "<td>" . $row['mindestbestand'] . "</td>";
            echo "<td>" . $row['verpackung'] ?? '-' . "</td>";
            echo "<td>" . $row['lagerplatz'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    
    $mysqli->close();
    ?>

    <br><br>
    <form method="POST" action="">
        <label for="search">Artikel-Nr. suchen:</label>
        <input type="text" name="search" value="<?php echo $id; ?>" placeholder="z.B. G001">
        <button type="submit">Suchen</button>
    </form>

</body>
</html>
