package yamlTestTwo.JsonUtil;

import yamlTestTwo.Token;

public class JsonElement implements JsonValue {

    private ValueType type;

    private String value;

    public JsonElement(Token token) {
        switch (token.getTokenType()) {
            case STRING:
                type = ValueType.STRING;
                break;
            case BOOL:
                type = ValueType.BOOL;
                break;
            case FLOAT:
                type = ValueType.FLOAT;
                break;
            case INT:
                type = ValueType.INT;
                break;
            case BIGDECIMAL:
                type = ValueType.BIGDECIMAL;
                break;

        }
        value = token.toString();
//        if (type == ValueType.STRING) {
//            value = "\"" + value + "\"";
//        }
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value;
    }

    public ValueType getType() {
        return type;
    }
}
