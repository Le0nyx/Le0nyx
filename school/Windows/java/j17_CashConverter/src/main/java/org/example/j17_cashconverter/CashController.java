package org.example.j17_cashconverter;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class CashController {
    @FXML
    public Button ConvertButton;

    @FXML
    private TextArea OutputArea;

    @FXML
    private ChoiceBox<String> LowerChoiceBox;

    @FXML
    private ChoiceBox<String> UpperChoiceBox;

    @FXML
    private TextField InputArea;

    @FXML
    public void initialize() {
        ObservableList<String> options = FXCollections.observableArrayList("€ Euro", "$ Dollar", "¥ Yen", "£ Sterling");
        UpperChoiceBox.setItems(options);
        LowerChoiceBox.setItems(options);

        UpperChoiceBox.setValue("€ Euro");
        LowerChoiceBox.setValue("$ Dollar");
    } //  € , $  , ¥ , £

    @FXML
    private void handleButtonClick() {
        String inputText = InputArea.getText();
        String upperChoice = UpperChoiceBox.getValue();
        String lowerChoice = LowerChoiceBox.getValue();

        OutputArea.clear(); // clears all in there

        try {
            // convert to cash format wanted
            double convertedAmount = Cash.convertCurrency(Double.parseDouble(inputText), upperChoice, lowerChoice);

            // out
            String convertedCurrency = String.format("%.2f %s", convertedAmount, lowerChoice);
            OutputArea.appendText(convertedCurrency);
        } catch (NumberFormatException e) {
            OutputArea.appendText("Invalid input. Please enter a valid number.");
        }

    } // end of buttonclick

}
