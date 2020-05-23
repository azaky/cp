{
ID: a_zaky01
PROG: heritage
LANG: PASCAL
}

var
  in_order,pre_order,post_order:string;
  fin,fout:text;

procedure process(in_order,pre_order:string);
  var
    root:integer;

  begin
    post_order:=pre_order[1]+post_order;
    root:=pos(pre_order[1],in_order);
    if root<length(in_order) then process(copy(in_order,root+1,length(in_order)-root),copy(pre_order,root+1,length(pre_order)-root));
    if root>1 then process(copy(in_order,1,root-1),copy(pre_order,2,root-1));
  end;

begin
  assign(fin,'heritage.in');
  assign(fout,'heritage.out');
  reset(fin);
  rewrite(fout);
  readln(fin,in_order);
  readln(fin,pre_order);
  post_order:='';
  process(in_order,pre_order);
  writeln(fout,post_order);
  close(fin);
  close(fout);
end.
