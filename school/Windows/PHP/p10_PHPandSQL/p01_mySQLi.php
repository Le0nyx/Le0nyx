<?php
    require_once 'SECRET.php';
    $mysqli = new mysqli($host, $user, $pass, "STASTLEO_DB2");

    echo $mysqli->host_info . "<br>" . $mysqli->server_info . "<br>" . $mysqli->stat();

    echo "<br>" . "----------------------------------" . "<br>";

    $queryResult = $mysqli->query("SELECT * FROM myTable");

    print_R($queryResult->fetch_assoc());

    $mysqli->close();
?>
