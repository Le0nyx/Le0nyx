package org.example.j17_cashconverter;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Screen;
import javafx.stage.Stage;

import java.io.IOException;

public class CashApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(CashApplication.class.getResource("CashConverterView.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), Screen.getPrimary().getOutputScaleX() * 420, Screen.getPrimary().getOutputScaleY() * 340);
        stage.setTitle("Cash Converter");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}