package yamlTestTwo;

import yamlTestTwo.JsonUtil.JsonFormat;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) throws IOException, LexicalException {
//        Lexer lexer = new Lexer("E:\\Woo\\Homework\\sample.yml");
//        try {
//            lexer.parse();
//            ArrayList<Token> tokenArrayList = lexer.getTokenList();
//            Iterator<Token> it1 = lexer.getTokenList().iterator();
//            while(it1.hasNext()){
//                System.out.println(it1.next());
//            }
//
//        }catch (LexicalException e){
//            e.printStackTrace();
//        }
//
//        Parser parser = new Parser();
//        JsonFormat json = parser.parseYaml("E:\\Woo\\Homework\\sample.yml");
////        int index = path.lastIndexOf(".json");
////        String newPath = path.substring(0, index) + ".pretty.json";
//        BufferedWriter out = new BufferedWriter(new FileWriter("E:\\Woo\\Homework\\sample.json"));
//        out.write(json.toString());
//        out.close();
//
//        System.out.println(Find.findValue("array[3][2]"));


        if (args.length == 1) {
            String path = args[0];
            if (!path.endsWith(".yml")) {
                System.out.println("file is not yaml format");
                System.exit(0);
            }

            Lexer lexer = new Lexer(path);
            try {
                lexer.parse();
                Parser parser = new Parser();
                if(parser != null){
                    System.out.println("valid");
                }

            }catch (LexicalException e){
//                e.printStackTrace();
                System.out.println(e.getMessage());
            }



        }

        if(args.length == 2){
            if (!args[0].equals("-json") && !args[0].equals("-parse")) {
                System.out.println("unrecognised option: " + args[0]);
            }
            if(args[0].equals("-json")){
                String path = args[1];
                if (!path.endsWith(".yml")) {
                    System.out.println("file is not yaml format");
                    System.exit(0);
                }
                Lexer lexer = new Lexer(path);
                try {
                    lexer.parse();
                    Parser parser = new Parser();
                    JsonFormat json = parser.parseYaml(path);
                    int index = path.lastIndexOf(".yml");
                    String newPath = path.substring(0, index) + ".json";
                    BufferedWriter out = new BufferedWriter(new FileWriter(newPath));
                    out.write(json.toString());
                    out.close();
                    System.out.println("The file: "+ newPath + " had been created.");
                }catch (LexicalException e){
//                e.printStackTrace();
                    System.out.println(e.getMessage());
                }

            }
            else if(args[0].equals("-parse")){
                String path = args[1];
                if (!path.endsWith(".yml")) {
                    System.out.println("file is not yaml format");
                    System.exit(0);
                }
                Lexer lexer = new Lexer(path);
                try {
                    lexer.parse();
                    Parser parser = new Parser();
                    if(parser != null){
                        System.out.println("valid");
                    }

                }catch (LexicalException e){
//                e.printStackTrace();
                    System.out.println(e.getMessage());
                }
            }

        }

        if(args.length == 3){
            if (!args[0].equals("-find")){
                System.out.println("unrecognised option: " + args[0]);
            }
            String location = args[1];
            String path = args[2];
            if (!path.endsWith(".yml")) {
                System.out.println("file is not yaml format");
                System.exit(0);
            }
            try{
                System.out.println(Find.findValue(location,path));
            }catch (LexicalException e){
                e.printStackTrace();
            }


        }





    }
}
