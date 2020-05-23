var
  n,i,tc:longint; found:boolean;
  used:array[0..9] of boolean;

function f(num:longint):string;
  var
    res:string;
    i:longint;
  
  begin
    res := '';
    for i:=1 to 5 do
      begin
        res := chr((num mod 10)+48)+res;
        num := num div 10;
      end;
    exit(res);
  end;

procedure test(num,k:longint);
  var
    i,den:longint;
    s:string;
    x:array[0..9] of longint;
  
  begin
    if k=5 then
      begin
        if num mod n <> 0 then exit;
        den := num div n; s := f(num)+' / '+f(den)+' = ';
        fillchar(x,sizeof(x),0);
        for i:=1 to 5 do
          begin
            if x[num mod 10]>0 then exit;
            inc(x[num mod 10]); num:=num div 10;
            if x[den mod 10]>0 then exit;
            inc(x[den mod 10]); den:=den div 10;
          end;
        writeln(s,n); found := true;
        exit;
      end;
    for i:=0 to 9 do
      if not used[i] then
        begin used[i]:=true; test(10*num+i,k+1); used[i]:=false; end;
  end;

begin
  repeat
    readln(n); if n=0 then break;
    if tc=0 then begin tc:=1; end else writeln;
    fillchar(used,sizeof(used),false);
    found := false;
    test(0,0);
    if not found then writeln('There are no solutions for ',n,'.');
  until false;
end.
