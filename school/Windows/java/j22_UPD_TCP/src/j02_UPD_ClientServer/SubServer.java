package j02_UPD_ClientServer;

import java.io.*;
import java.net.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 * Simple SubServer:
 * - connects to MainServer, registers name and commands
 * - responds to lines "EXEC <cmdline> FROM <username>" with a single-line response
 * /subregister <name>         - register subserver name
 *    /registercmd <cmd>          - announce a command handled by this subserver (stored as "/cmd")
 *    MainServer forwards matching commands to subservers as:
 *      EXEC <client-line> FROM <username>
 *    SubServer must reply with one newline-terminated line; MainServer returns:
 *      SUBSERVER_RESPONSE <that-line>
 */
public class SubServer {
    private static final String MAIN_HOST = "127.0.0.1";
    private static final int MAIN_PORT = 8888;

    public static void main(String[] args) throws Exception {
        String name = args.length > 0 ? args[0] : "timesrv";
        try (Socket s = new Socket(MAIN_HOST, MAIN_PORT);
             BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
             PrintWriter out = new PrintWriter(s.getOutputStream(), true)) {

            // Register with main server
            out.println("/subregister " + name);
            out.println("/registercmd time");
            out.println("/registercmd date");
            out.println("/registercmd calc");
            out.println("/registercmd filelist");
            out.println("/registercmd get");

            // Reader loop: process incoming EXEC commands and respond
            String l;
            while ((l = in.readLine()) != null) {
                System.out.println("[MAIN] " + l);
                if (l.startsWith("EXEC ")) {
                    // EXEC <cmdline> FROM <username>
                    String payload = l.substring("EXEC ".length());
                    int fromIdx = payload.lastIndexOf(" FROM ");
                    String cmdline = (fromIdx == -1) ? payload : payload.substring(0, fromIdx);
                    String resp = handleCommand(cmdline.trim());
                    out.println(resp);
                } else {
                    // Other messages from server can be logged
                    // (not used in our protocol for now)
                }
            }
        } catch (IOException e) {
            System.out.println("Disconnected from MainServer: " + e.getMessage());
        }
    }

    private static String handleCommand(String cmdline) {
        String[] parts = cmdline.split("\\s+", 2);
        String cmd = parts[0];
        String arg = parts.length > 1 ? parts[1] : "";
        switch (cmd) {
            case "/time":
                return LocalDateTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"));
            case "/date":
                return LocalDateTime.now().toLocalDate().toString();
            case "/calc":
                try { return "CALC " + evalSimple(arg); } catch (Exception e) { return "CALC_ERROR " + e.getMessage(); }
            case "/filelist":
                return "FILES sample1.txt,sample2.txt";
            case "/get":
                return "GET_OK " + arg;
            default:
                return "UNKNOWN";
        }
    }

    // very small expression evaluator (no parentheses)
    private static double evalSimple(String expr) {
        expr = expr.replaceAll("\\s+","");
        java.util.List<Double> numbers = new java.util.ArrayList<>();
        java.util.List<Character> ops = new java.util.ArrayList<>();
        StringBuilder cur = new StringBuilder();
        for (int i=0;i<expr.length();i++) {
            char c = expr.charAt(i);
            if (c=='+'||c=='-'||c=='*'||c=='/') {
                numbers.add(Double.parseDouble(cur.toString()));
                ops.add(c); cur.setLength(0);
            } else cur.append(c);
        }
        if (cur.length()>0) numbers.add(Double.parseDouble(cur.toString()));
        for (int i=0;i<ops.size();) {
            char op = ops.get(i);
            if (op=='*' || op=='/') {
                double a = numbers.get(i), b = numbers.get(i+1), r = (op=='*') ? a*b : a/b;
                numbers.set(i, r); numbers.remove(i+1); ops.remove(i);
            } else i++;
        }
        double res = numbers.get(0);
        for (int i=0;i<ops.size();i++){
            char op = ops.get(i);
            double b = numbers.get(i+1);
            if (op=='+') res += b; else res -= b;
        }
        return res;
    }
}
