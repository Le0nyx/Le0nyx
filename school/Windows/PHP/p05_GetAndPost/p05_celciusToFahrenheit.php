<?php
if (isset($_GET['celsius']) && $_GET['celsius'] !== '') {
    $celsius = floatval($_GET['celsius']);
    
    // Convert Celsius to Fahrenheit: F = (C × 9/5) + 32
    $fahrenheit = ($celsius * 9/5) + 32;
    
    echo "<h2>Temperature Converter</h2>";
    echo "<p>{$celsius}°C = " . number_format($fahrenheit, 2) . "°F</p>";
    echo "<hr>";
}
?>

<h2>Celsius to Fahrenheit Converter</h2>
<form method="GET">
    <label for="celsius">Enter Celsius:</label>
    <input type="number" step="0.01" name="celsius" id="celsius" value="<?php echo isset($_GET['celsius']) ? htmlspecialchars($_GET['celsius']) : ''; ?>" required>
    <button type="submit">Convert</button>
</form>
