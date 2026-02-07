
<body>
    <h1>Autowerkstatt</h1>
    
    <form method="POST" action="">
        <label for="reifen">Reifen (Anzahl):</label>
        <input type="number" name="reifen" placeholder="z.B. 4">
        <br><br>

        <label for="oel">Öl (Liter):</label>
        <input type="number" name="oel" placeholder="z.B. 5">
        <br><br>

        <label for="zuendkerzen">Zündkerzen (Anzahl):</label>
        <input type="number" name="zuendkerzen" placeholder="z.B. 8">
        <br><br>

        <label for="herkunft">Wie haben Sie von uns erfahren?</label>
        <select id="herkunft" name="herkunft" required>
            <option value="">-- Bitte wählen --</option>
            <option value="stammkunde">Ich bin Stammkunde</option>
            <option value="tv_werbung">TV Werbung</option>
            <option value="telefonbuch">Telefonbuch</option>
            <option value="mundpropaganda">Mundpropaganda</option>
        </select>
        <br><br>

        <button type="submit">Bestellung absenden</button>
    </form>
</body>
</html>
<?php
    if ($_POST) {
        echo "<h3>Bestellung eingegangen!</h3>";
        echo "Reifen: " . $_POST['reifen'] . "<br>";
        echo "Öl: " . $_POST['oel'] . "<br>";
        echo "Zündkerzen: " . $_POST['zuendkerzen'] . "<br>";
        echo "Herkunft: " . $_POST['herkunft'] . "<br>";
        echo "Datum: " . date("d.m.Y H:i:s") . "<br>";
    }
?>

<?php
    if ($_POST) {
        $reifen = (int)$_POST['reifen'] * 100;
        $oel = (int)$_POST['oel'] * 18;
        $zuendkerzen = (int)$_POST['zuendkerzen'] * 4;
        $endsumme = $reifen + $oel + $zuendkerzen;
        
        $steuer = $endsumme * 0.22;
        $gesamtbetrag = $endsumme + $steuer;
        
        echo "<br>Endsumme: " . number_format($endsumme, 2, ',', '.') . " € <br>";
        echo "Steuer (22%): " . number_format($steuer, 2, ',', '.') . " € <br>";
        echo "Gesamtbetrag (inkl. Steuer): " . number_format($gesamtbetrag, 2, ',', '.') . " € <br>";
    }
?>
