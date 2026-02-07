<?php
    class Fabrik {
        private $standort;
        private $mitarbeiterAnzahl;
        

        function __construct($standort, $mitarbeiterAnzahl){
            $this->standort = $standort;
            $this->mitarbeiterAnzahl = $mitarbeiterAnzahl;
        }


        function produktHerstellen(){
            echo "Neues Produkt hergestellt!";
        }

        function setStandort($standort) { $this->standort = $standort; }
        function getStandort() { return $this->standort; }
        function setMitarbeiterAnzahl($mitarbeiterAnzahl) { $this->mitarbeiterAnzahl = $mitarbeiterAnzahl; }
        function getMitarbeiterAnzahl() { return $this->mitarbeiterAnzahl; }
   
    }

?>

<?php
    $Fabrik1 = new Fabrik("Bruneck", 30);

    echo "Outputs: <br>";
    echo $Fabrik1->getStandort() . "<br>";
    $Fabrik1->produktHerstellen();

    echo "<br>";
    $Fabrik1->setStandort("Innsbruck");
    echo "Neuer Standort: " . $Fabrik1->getStandort() . "<br>";

    $Fabrik1->setMitarbeiterAnzahl(50);
    echo "Neue Mitarbeiteranzahl: " . $Fabrik1->getMitarbeiterAnzahl() . "<br>";
?>
