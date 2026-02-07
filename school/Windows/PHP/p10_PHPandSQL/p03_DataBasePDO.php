<?php
    require_once 'SECRET.php';
    
    try {
        $pdo = new PDO("mysql:host=$host;dbname=STASTLEO_DB2", $user, $pass);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        
        echo "Connected to: $host<br>";
        echo "Server version: " . $pdo->getAttribute(PDO::ATTR_SERVER_VERSION) . "<br>";
        echo "Connection status: " . $pdo->getAttribute(PDO::ATTR_CONNECTION_STATUS) . "<br>";
        
        echo "<br>----------------------------------<br>";
        
        $stmt = $pdo->prepare("SELECT * FROM myTable");
        $stmt->execute();
        
        $result = $stmt->fetch(PDO::FETCH_ASSOC);
        print_r($result);
        
        $pdo = null;
        
    } catch (PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }
?>