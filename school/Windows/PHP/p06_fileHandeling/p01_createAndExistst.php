<?php
    $fileread = "test1.txt";

    if(file_exists($fileread) == true){
        echo "File exists\n";
        echo filesize("$fileread");
        echo "\n";
        echo file_get_contents("$fileread");
        echo "\n";

    }else{ // creates a new one on each reload of site
        $file = fopen("$fileread", "w");
        fwrite($file, "Hello There\n");
        fclose($file);
        echo "created a file";
    }

?>