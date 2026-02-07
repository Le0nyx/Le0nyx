<?php

if (isset($_GET['num1']) && isset($_GET['num2']) && isset($_GET['operation'])) {
    $num1 = floatval($_GET['num1']);
    $num2 = floatval($_GET['num2']);
    $operation = $_GET['operation'];
    $result = null;
    $error = null;

    switch ($operation) {
        case 'add':
            $result = $num1 + $num2;
            break;
        case 'subtract':
            $result = $num1 - $num2;
            break;
        case 'multiply':
            $result = $num1 * $num2;
            break;
        case 'divide':
            if ($num2 != 0) {
                $result = $num1 / $num2;
            } else {
                $error = "Cannot divide by zero";
            }
            break;
        default:
            $error = "Invalid operation. Use: add, subtract, multiply, or divide";
    }
} else {
    $num1 = '';
    $num2 = '';
    $operation = '';
    $error = "Please provide num1, num2, and operation parameters";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Calculator - GET Method</title>
</head>
<body>
    <h1>URL Calculator</h1>
    
    <form method="GET" action="">
        <label>Number 1: <input type="number" step="any" name="num1" value="<?php echo htmlspecialchars($num1); ?>" required></label><br><br>
        <label>Number 2: <input type="number" step="any" name="num2" value="<?php echo htmlspecialchars($num2); ?>" required></label><br><br>
        <label>Operation: 
            <select name="operation" required>
                <option value="">-- Select --</option>
                <option value="add" <?php echo ($operation == 'add') ? 'selected' : ''; ?>>Add (+)</option>
                <option value="subtract" <?php echo ($operation == 'subtract') ? 'selected' : ''; ?>>Subtract (-)</option>
                <option value="multiply" <?php echo ($operation == 'multiply') ? 'selected' : ''; ?>>Multiply (×)</option>
                <option value="divide" <?php echo ($operation == 'divide') ? 'selected' : ''; ?>>Divide (÷)</option>
            </select>
        </label><br><br>
        <button type="submit">Calculate</button>
    </form>
    
    <?php if (isset($result)): ?>
        <h2>Result: <?php echo $num1 . ' ' . $operation . ' ' . $num2 . ' = ' . $result; ?></h2>
    <?php endif; ?>
    
    <?php if (isset($error) && isset($_GET['operation'])): ?>
        <h2 style="color: red;">Error: <?php echo $error; ?></h2>
    <?php endif; ?>
    
    <h3>Usage:</h3>
    <p>Use the form above OR add parameters to the URL:</p>
    <ul>
        <li>?num1=10&num2=5&operation=add</li>
        <li>?num1=10&num2=5&operation=subtract</li>
        <li>?num1=10&num2=5&operation=multiply</li>
        <li>?num1=10&num2=5&operation=divide</li>
    </ul>
</body>
</html>