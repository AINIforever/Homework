package yamlTestTwo;


public enum TokenType{
    ERROR("error"),
    INT("int"),
    FLOAT("float"),
    DOUBLE("double"),
    BIGDECIMAL("bigdecimal"),
    STRING("string"),
    BOOL("bool"),
//    TRUE("true", "true"),
//    FALSE("false", "false"),
//    NULL("null", "null"),
//    COMMA(",", ","),
//    COMMENT("comment"),
//    COLON(":", ":"),
//    HORILINE("-","-"),
    DOT("."),
    IDENTIFIER("identifier"),
    UNDEFINED("undefined"),
    ARRAY("array"),
    END("end");

    private TokenType(String name) {
        this.name = name;

    }

    private String name;

    public String getName(){
        return this.name;
    }

   }

