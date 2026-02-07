<?php
// Globale Parameter
$rows = 10;  // Anzahl der Zeilen
$bgColor1 = "#ffffff";  // Weiß
$bgColor2 = "#e0e0e0";  // Grau

?>

<body>
    <table>
        <thead>
            <tr>
                <th>Zeilennr.</th>
                <th>Text</th>
            </tr>
        </thead>
        <tbody>
            <?php
            for ($i = 1; $i <= $rows; $i++) {
                $bgColor = ($i % 2 == 1) ? $bgColor1 : $bgColor2;
                echo "<tr style='background-color: $bgColor;'>";
                echo "<td>$i</td>";
                echo "<td>Dies ist Zeile Nummer $i</td>";
                echo "</tr>";
            }
            ?>
        </tbody>
    </table>
</body>

