<?php

$n = isset($_GET['n']) ? (int)$_GET['n'] : 10;

// Ensure n is positive
if ($n < 1) {
    $n = 10;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Square Numbers Table</title>
</head>
<body>
    <h1>Square Numbers Table</h1>
    <p>Showing squares from 1 to <?php echo $n; ?></p>
    
    <table>
        <thead>
            <tr>
                <th>Number</th>
                <th>Square</th>
            </tr>
        </thead>
        <tbody>
            <?php for ($i = 1; $i <= $n; $i++): ?>
            <tr>
                <td><?php echo $i; ?></td>
                <td><?php echo $i * $i; ?></td>
            </tr>
            <?php endfor; ?>
        </tbody>
    </table>
    
    <form method="GET">
        <label>Enter n: <input type="number" name="n" value="<?php echo $n; ?>" min="1"></label>
        <button type="submit">Generate</button>
    </form>
</body>
</html>