var
  a:longint;

begin
  readln(a);
  case a of
    1:writeln(2);//this is test2
    2:writeln(3);//this is test4
    3:writeln(1);//this is test1
    4:writeln(2);//this is test3
    5:writeln(1);//this is test5
  end;
end.
{
	* test1:3|1
	* test2:1|2
	* test3:4|2
	* test4:2|3
	* test5:5|1
}
