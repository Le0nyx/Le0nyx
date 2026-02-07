package org.example.j17_cashconverter;

public class Cash {
    private static double convertToEuro(double amount, String currencyType) {
        double conversionRate;

        switch (currencyType) {
            case "€ Euro":
                conversionRate = 1.0;
                break;
            case "$ Dollar":
                conversionRate = 0.9543; // 1 USD = 0.9543 EUR
                break;
            case "¥ Yen":
                conversionRate = 0.00625; // 1 JPY = 0.00625 EUR
                break;
            case "£ Sterling":
                conversionRate = 1.200968; // 1 GBP = 1.200968 EUR
                break;
            default:
                return 0.0;
        }
        return amount * conversionRate;
    }

    private static double convertFromEuro(double amount, String currencyType) {
        double conversionRate;

        switch (currencyType) {
            case "€ Euro":
                conversionRate = 1.0;
                break;
            case "$ Dollar":
                conversionRate = 1.0478; // 1 EUR = 1.0478 USD
                break;
            case "¥ Yen":
                conversionRate = 160.0; // 1 EUR = 160 JPY
                break;
            case "£ Sterling":
                conversionRate = 0.8326; // 1 EUR = 0.8326 GBP
                break;
            default:
                return 0.0;
        }
        return amount * conversionRate;
    }

    // convert to one currency so its easy to get to others
    // only protected to be able to accessed in package
    protected static double convertCurrency(double amount, String fromCurrency, String toCurrency) {
        return convertFromEuro(convertToEuro(amount, fromCurrency), toCurrency);
    }
}
