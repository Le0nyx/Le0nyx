package org.example.j16_javafxfirst;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Screen;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));

        // load it so it scales with screensize (gives back double value of how much it differs)
        Scene scene = new Scene(fxmlLoader.load(), Screen.getPrimary().getOutputScaleX() * 340, Screen.getPrimary().getOutputScaleY() * 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}