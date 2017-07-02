import org.junit.*;
import org.junit.runner.*;
import org.junit.runners.MethodSorters;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.*;
import java.util.List;

@FixMethodOrder(MethodSorters.NAME_ASCENDING)

public class PrinttokensTest
{
  @Before
  public void setUp () {
  }
//
//Tests for function get_token
//
  @Test
  public void test_get_tokenNULL()
  {
    Printtokens token = new Printtokens();
    assertEquals(null, token.get_token(token.open_token_stream("file.txt")));
  }

  @Test
  public void test_get_tokenNULL2()
  {
    Printtokens token = new Printtokens();
    assertEquals(null, token.get_token(token.open_token_stream("file2.txt")));
  }

  @Test
  public void test_get_tokenlparen()
  {
    Printtokens token = new Printtokens();
    assertEquals("(", token.get_token(token.open_token_stream("file3.txt")));
  }

  @Test
  public void test_get_tokenquote()
  {
    Printtokens token = new Printtokens();
    assertEquals("\"\n", token.get_token(token.open_token_stream("file4.txt")));
  }

  @Test
  public void test_get_tokensemicolon()
  {
    Printtokens token = new Printtokens();
    assertEquals(";(", token.get_token(token.open_token_stream("file5.txt")));
  }

  @Test
  public void test_get_tokenbk()
  {
    Printtokens token = new Printtokens();
    assertEquals("bk", token.get_token(token.open_token_stream("file6.txt")));
  }

  @Test
  public void test_get_tokenblparen()
  {
    Printtokens token = new Printtokens();
    assertEquals("(b", token.get_token(token.open_token_stream("file7.txt")));
  }

  @Test
  public void test_get_tokenquoteb()
  {
    Printtokens token = new Printtokens();
    assertEquals("\"b\n", token.get_token(token.open_token_stream("file8.txt")));
  }

  @Test
  public void test_get_tokenbb()
  {
    Printtokens token = new Printtokens();
    assertEquals("bb", token.get_token(token.open_token_stream("file9.txt")));
  }

  @Test
  public void test_get_tokencolonb()
  {
    Printtokens token = new Printtokens();
    assertEquals(";b", token.get_token(token.open_token_stream("file10.txt")));
  }
//
//Tests for function is_token_end
//
  @Test
  public void test_is_token_end_true1()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_token_end(5, -1));
  }

  @Test
  public void test_is_token_end_true2()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_token_end(1, 10));
  }

  @Test
  public void test_is_token_end_false1()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_token_end(1, 99));
  }

  @Test
  public void test_is_token_end_true3()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_token_end(2, 13));
  }

  @Test
  public void test_is_token_end_false2()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_token_end(2, 99));
  }

  @Test
  public void test_is_token_end_true4()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_token_end(5, 40));
  }

  @Test
  public void test_is_token_end_true5()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_token_end(5, 32));
  }

  @Test
  public void test_is_token_end_false3()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_token_end(5, 99));
  }
//
//Tests for function token_type
//
  @Test
  public void test_token_type_1()
  {
    Printtokens token = new Printtokens();
    assertEquals(1, token.token_type("and"));
  }

  @Test
  public void test_token_type_2()
  {
    Printtokens token = new Printtokens();
    assertEquals(2, token.token_type("("));
  }

  @Test
  public void test_token_type_3()
  {
    Printtokens token = new Printtokens();
    assertEquals(3, token.token_type("a1"));
  }

  @Test
  public void test_token_type_41()
  {
    Printtokens token = new Printtokens();
    assertEquals(41, token.token_type("321"));
  }

  @Test
  public void test_token_type_42()
  {
    Printtokens token = new Printtokens();
    assertEquals(42, token.token_type("\"123\""));
  }

  @Test
  public void test_token_type_43()
  {
    Printtokens token = new Printtokens();
    assertEquals(43, token.token_type("#b"));
  }

  @Test
  public void test_token_type_5()
  {
    Printtokens token = new Printtokens();
    assertEquals(5, token.token_type(";Hello"));
  }

  @Test
  public void test_token_type_0()
  {
    Printtokens token = new Printtokens();
    assertEquals(0, token.token_type("112A"));
  }
//
//Tests for function is_comment
//
  @Test
  public void test_is_commenttrue()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_comment(";Hello"));
  }

  @Test
  public void test_is_commentfalse()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_comment("Bye"));
  }
//
//Tests for function is_keyword
//
  @Test
  public void test_is_keywordtrue()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_keyword("and"));
  }

  @Test
  public void test_is_keywordfalse()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_keyword("will"));
  }
//
//Tests for function is_char_constant
//
  @Test
  public void test_is_char_constant_true()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_char_constant("#b"));
  }

  @Test
  public void test_is_char_constant_false()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_char_constant("#big"));
  }
//
//Tests for function is_num_constant
//
  @Test
  public void test_is_num_constant_false1()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_num_constant("A2"));
  }

  @Test
  public void test_is_num_constant_true1()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_num_constant("1"));
  }

  @Test
  public void test_is_num_constant_false2()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_num_constant("1A"));
  }

  @Test
  public void test_is_num_constant_true2()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_num_constant("12"));
  }
//
//Tests for function is_str_constant
//
  @Test
  public void test_is_str_constant_false1()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_str_constant("123"));
  }

  @Test
  public void test_is_str_constant_false2()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_str_constant("\""));
  }

  @Test
  public void test_is_str_constant_true1()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_str_constant("\"b\""));
  }

  @Test
  public void test_is_str_constant_false3()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_str_constant("\"a"));
  }
//
//Tests for function is_identifier
//
  @Test
  public void test_is_identifier_false1()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_identifier("1a"));
  }

  @Test
  public void test_is_identifier_true1()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_identifier("a"));
  }
  @Test
  public void test_is_identifier_false2()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_identifier("a\""));
  }

  @Test
  public void test_is_identifier_true2()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_identifier("a2"));
  }
//
//Tests for function is_spec_symbol
//
  @Test
  public void test_is_spec_symbol_lparen()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol('('));
  }

  @Test
  public void test_is_spec_symbol_rparen()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol(')'));
  }

  @Test
  public void test_is_spec_symbol_lsquare()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol('['));
  }

  @Test
  public void test_is_spec_symbol_rsquare()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol(']'));
  }

  @Test
  public void test_is_spec_symbol_quote()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol('\''));
  }

  @Test
  public void test_is_spec_symbol_bquote()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol('`'));
  }

  @Test
  public void test_is_spec_symbol_comma()
  {
    Printtokens token = new Printtokens();
    assertEquals(true, token.is_spec_symbol(','));
  }

  @Test
  public void test_is_spec_symbol_false()
  {
    Printtokens token = new Printtokens();
    assertEquals(false, token.is_spec_symbol('b'));
  }

  @After
  public void tearDown () {
  }
}
