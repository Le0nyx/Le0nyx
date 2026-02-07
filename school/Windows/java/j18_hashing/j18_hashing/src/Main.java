public class Main {
    public static void main(String[] args) {
        HashTable ht = new HashTable();


    }
}

/*
Erstelle eine Hashtabelle zur Verwaltung der SchülerInnen einer Klasse. Eine Klasse kann maximal 28
SchülerInnen haben. Überlege dir selber eine Hashfunktion. Arbeite mit Arrays und Listen. Stelle eine
Methode zur Berechnung des Belegungsfaktors zur Verfügung.
Die Einträge der SchülerInnen beinhalten: Vorname, Nachname, Geburtsdatum, Adresse (mehrere
Attribute). Wähle für die Hashtabelle einen Schlüssel aus: z.B. Nachname (dann mit der
Einschränkung, dass der Nachname eindeutig sein muss, Nachname und Geb.Datum, ...).

Zusatz:
Die SchülerInnen sollen am Ende des Programms in ein File geschrieben werden. Am Anfang soll aus
diesem File ausgelesen werden. Während der Laufzeit des Programms kann man Schüler hinzufügen,
löschen, die Schüler ausgeben, den Belegungsfaktor berechnen.

Zusatz 2:
Wenn der Belegungsfaktor 75% überschreitet, soll die Hashtabelle neu organisiert werden, indem sie
um 20% vergrößert wird.

Zusatz 3:
Programmiere eine grafische Oberfläche für die Eingabe der Daten und Ausgabe von Informationen
über die Hashtabelle (Größe, Belegungsfaktor, Kollisionen, usw.)
 */