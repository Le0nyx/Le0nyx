<?php

$fruchtString = "Apfel,Birne,Banane,Kirsche";
$fruchtArray = explode(",", $fruchtString);

$fruchtArray[] = "Mango";
$neuerString = implode(";", $fruchtArray);

echo $neuerString;

?>