<?php
// Snackautomat mit mehreren Produkten

// Produktdaten definieren
$produkte = [
    'chips' => ['name' => 'Chips', 'preis' => 2.50],
    'schoko' => ['name' => 'Schokolade', 'preis' => 1.80],
    'cola' => ['name' => 'Cola', 'preis' => 2.00],
    'wasser' => ['name' => 'Wasser', 'preis' => 1.50],
    'keks' => ['name' => 'Kekse', 'preis' => 1.20]
];

$gesamtpreis = 0;
$bestellung = [];

// GET-Daten verarbeiten (Produktauswahl)
if (!empty($_GET)) {
    foreach ($produkte as $key => $produkt) {
        if (isset($_GET[$key]) && $_GET[$key] > 0) {
            $menge = (int)$_GET[$key];
            $bestellung[$key] = [
                'name' => $produkt['name'],
                'menge' => $menge,
                'preis' => $produkt['preis'],
                'summe' => $menge * $produkt['preis']
            ];
            $gesamtpreis += $bestellung[$key]['summe'];
        }
    }
}

// POST-Daten verarbeiten (Bezahlung)
$restgeld = null;
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['geld'])) {
    $geld = (float)$_POST['geld'];
    $restgeld = $geld - $gesamtpreis;
}
?>

<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <title>Snackautomat</title>
    <style>
        body { font-family: Arial, sans-serif; max-width: 600px; margin: 50px auto; }
        .produkt { margin: 10px 0; }
        .box { border: 1px solid #ccc; padding: 15px; margin: 20px 0; }
        input[type="number"] { width: 60px; }
        button { padding: 10px 20px; cursor: pointer; }
        .erfolg { color: green; }
        .fehler { color: red; }
    </style>
</head>
<body>
    <h1>🍫 Snackautomat</h1>

    <!-- Schritt 1: Produktauswahl -->
    <div class="box">
        <h2>Produkte auswählen</h2>
        <form method="get">
            <?php foreach ($produkte as $key => $produkt): ?>
                <div class="produkt">
                    <label>
                        <?= $produkt['name'] ?> (<?= number_format($produkt['preis'], 2) ?> €):
                        <input type="number" name="<?= $key ?>" min="0" value="<?= $_GET[$key] ?? 0 ?>">
                    </label>
                </div>
            <?php endforeach; ?>
            <button type="submit">Auswahl bestätigen</button>
        </form>
    </div>

    <?php if (!empty($bestellung)): ?>
        <!-- Bestellübersicht -->
        <div class="box">
            <h2>Ihre Bestellung:</h2>
            <ul>
                <?php foreach ($bestellung as $item): ?>
                    <li>
                        <?= $item['menge'] ?>x <?= $item['name'] ?> 
                        (<?= number_format($item['preis'], 2) ?> € / Stück) = 
                        <?= number_format($item['summe'], 2) ?> €
                    </li>
                <?php endforeach; ?>
            </ul>
            <p><strong>Gesamtpreis: <?= number_format($gesamtpreis, 2) ?> €</strong></p>
        </div>

        <!-- Schritt 2: Bezahlung -->
        <div class="box">
            <h2>Bezahlung</h2>
            <form method="post">
                <label>
                    Eingeworfener Betrag (€):
                    <input type="number" name="geld" step="0.01" min="0" required>
                </label>
                <button type="submit">Bezahlen</button>
            </form>

            <?php if ($restgeld !== null): ?>
                <?php if ($restgeld >= 0): ?>
                    <p class="erfolg">
                        <strong>✓ Bezahlung erfolgreich!</strong><br>
                        Rückgeld: <?= number_format($restgeld, 2) ?> €
                    </p>
                <?php else: ?>
                    <p class="fehler">
                        <strong>✗ Zu wenig Geld!</strong><br>
                        Fehlbetrag: <?= number_format(abs($restgeld), 2) ?> €
                    </p>
                <?php endif; ?>
            <?php endif; ?>
        </div>
    <?php endif; ?>
</body>
</html>