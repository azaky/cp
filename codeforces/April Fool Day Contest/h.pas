type
  point=record p,q:longint; end;

var
  a,b:longint;
  x:point;

function ans(a,b:longint):point;
  label answer; 
  
  var
    k,l,pos:longint;
    x:point;
  
  begin
    if b=(1 shl (2*a))-1 then
      begin
        if a mod 2=1 then begin ans.p:=0; ans.q:=(1 shl a)-1; end
          else begin ans.p:=(1 shl a)-1; ans.q:=0; end;
        exit;
      end
    else if a=1 then
      begin
        if b=0 then begin ans.p:=0; ans.q:=0; end
        else if b=1 then begin ans.p:=1; ans.q:=0; end
        else if b=2 then begin ans.p:=1; ans.q:=1; end
        else if b=3 then begin ans.p:=0; ans.q:=2; end;
        goto answer;
      end;
    k:=1 shl (2*a-2); pos:=b div k; l:=1 shl (a-1);
    x:=ans(a-1,b-pos*k);
    if a mod 2=0 then
      case pos of
        0:begin ans.p:=x.p; ans.q:=x.q; end;
        1:begin ans.p:=x.q; ans.q:=x.p+l; end;
        2:begin ans.p:=x.q+l; ans.q:=x.p+l; end;
        3:begin ans.p:=2*l-x.p-1; ans.q:=l-x.q-1; end;
      end
    else
      case pos of
        0:begin ans.q:=x.q; ans.p:=x.p; end;
        1:begin ans.q:=x.p; ans.p:=x.q+l; end;
        2:begin ans.q:=x.p+l; ans.p:=x.q+l; end;
        3:begin ans.q:=2*l-x.q-1; ans.p:=l-x.p-1; end;
      end;
    answer:
    //writeln(a:4,b:4,k:4,pos:4,' ',ans.p,' ',ans.q,' ',x.p,' ',x.q);
  end;

begin
  readln(a,b);
  x:=ans(10,b); writeln(x.p,' ',x.q);
end.
