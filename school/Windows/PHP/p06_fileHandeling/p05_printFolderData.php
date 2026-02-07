<?php
    $items = scandir(getcwd());

    echo "Inhalt <br><br>";

    foreach ($items as $item) { echo filetype($item) . " = " . $item ." <br>"; }

?>
