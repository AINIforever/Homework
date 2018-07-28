package yamlTestTwo;

public class LexicalException extends Exception{
    private static final long serialVersionUID = 1L;
    public LexicalException(String message){
        super(message);
    }

    public LexicalException(String message, int lineNo, int pos){
        super("line:" + lineNo + ", " + "position" + pos + ": " + message);
    }

}

