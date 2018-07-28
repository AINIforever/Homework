
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineFactory;

public class CalculatorScriptEngineFactory
  implements ScriptEngineFactory
{
  public static final ScriptEngineFactory INSTANCE = null;

public String getEngineName()
  {
    return "Calculator Script Engine";
  }
  
  public String getEngineVersion()
  {
    return "1.0";
  }
  
  public List getExtensions()
  {
    return Arrays.asList(new String[] { "in", "calc" });
  }
  
  public List getMimeTypes()
  {
    return Arrays.asList(new String[] { "text/calculatorscript", "application/calculatorscript" });
  }
  
  public List getNames()
  {
    return Arrays.asList(new String[] { "CalculatorScript", "Calculator", "calculator", "Calc", "calc" });
  }
  
  public String getLanguageName()
  {
    return "Calculator Script";
  }
  
  public String getLanguageVersion()
  {
    return "1.0";
  }
  
  public Object getParameter(String paramString)
  {
    if (Objects.equals(paramString, "javax.script.engine")) {
      return getEngineName();
    }
    if (Objects.equals(paramString, "javax.script.engine_version")) {
      return getEngineVersion();
    }
    if (Objects.equals(paramString, "javax.script.name")) {
      return getNames();
    }
    if (Objects.equals(paramString, "javax.script.language")) {
      return getLanguageName();
    }
    if (Objects.equals(paramString, "javax.script.language_version")) {
      return getLanguageVersion();
    }
    return null;
  }
  
  public String getMethodCallSyntax(String paramString1, String paramString2, String... paramVarArgs)
  {
    return "";
  }
  
  public String getOutputStatement(String paramString)
  {
    return "print(" + paramString + ");";
  }
  
  public String getProgram(String... paramVarArgs)
  {
    return "";
  }
  
  public CalculatorScriptEngine getScriptEngine()
  {
    return new CalculatorScriptEngine();
  }
}

