package yamlTestTwo.JsonUtil;

import java.util.ArrayList;

public class JsonArray extends JsonFormat {

    private ValueType type;

    private ArrayList<JsonValue> array;

    public JsonArray() {
        array = new ArrayList<JsonValue>();
        type = ValueType.ARRAY;
    }

    public void addValue(JsonValue value) {
        array.add(value);
    }

    public JsonValue getValue(int index) {
        JsonValue value = null;
        try {
            value = array.get(index);
        } catch (IndexOutOfBoundsException e) {
            value = null;
        } finally {
            return value;
        }
    }

    @Override
    public String toString() {
        return format(1);
    }

    public ValueType getType() {
        return type;
    }

    public ArrayList<JsonValue> getArray() {
        return array;
    }



    @Override
    String format(int layer) {
        StringBuilder str = new StringBuilder();
        str.append("[\n");
        for (JsonValue value : array) {
            str.append(withSpace(layer));
            str.append(matchFormat(value, layer+1));
            str.append(",\n");
        }
        int lastIndex = str.length() - 2;
        if (str.charAt(lastIndex) == ',') str.deleteCharAt(lastIndex);
        str.append(withSpace(layer-1));
        str.append("]");
        return str.toString();
    }
}

