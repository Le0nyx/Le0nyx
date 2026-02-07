<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Factorial Calculator</title>
</head>
<body>
    <h1>Factorial Calculator</h1>
    
    <form method="GET" action="">
        <label for="number">Enter a number:</label>
        <input type="number" id="number" name="number" min="0" required>
        <button type="submit">Calculate</button>
    </form>

    <?php
    if (isset($_GET['number'])) {
        $number = intval($_GET['number']);
        
        if ($number < 0) {
            echo "<p style='color: red;'>Factorial is not defined for negative numbers.</p>";
        } else {
            $factorial = 1;
            for ($i = 1; $i <= $number; $i++) {
                $factorial *= $i;
            }
            echo "<p>The factorial of <strong>$number</strong> is: <strong>$factorial</strong></p>";
        }
    }
    ?>
</body>
</html>

