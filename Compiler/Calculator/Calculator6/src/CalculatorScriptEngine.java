import javax.script.AbstractScriptEngine;
import javax.script.Bindings;
import javax.script.ScriptContext;
import javax.script.ScriptEngineFactory;
import javax.script.ScriptException;
import javax.script.SimpleBindings;

import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

public class CalculatorScriptEngine extends AbstractScriptEngine {
    private List<Bindings> bindings = new ArrayList<>();

    @Override
    public Object eval(String script, ScriptContext context) throws ScriptException {
        Calculate calculate = new Calculate(script,script,context);
        context.setAttribute("result", calculate.getRes(), ScriptContext.ENGINE_SCOPE);
        double result = calculate.getRes();
        if(script.contains("print")) {
        	try {
				context.getWriter().write(calculate.getRes()+"\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
        return calculate.getRes();
    }

    @Override
    public Object eval(Reader reader, ScriptContext context) throws ScriptException {
        return null;
    }

    @Override
    public Bindings createBindings() {
        Bindings b = new SimpleBindings();
        bindings.add(b);
        return b;
    }

    @Override
    public ScriptEngineFactory getFactory() {
        return new CalculatorScriptEngineFactory();
    }
}