const
  maks=1000;

type
  st=record
       r,c,k:longint;
     end;

var
  r0,c0,rx,cx,n,i,j,max,imax,qtake,qsave:longint;
  state:st;
  ri,ci:array[1..maks*maks] of integer;
  a:array[1..maks,1..maks] of integer;
  queue:array[1..maks*maks] of st;

procedure check(state:st);
  var
    j:longint;
    temp:st;

  function range(temp:st):boolean;
    begin
      range:=false;
      if (temp.r>=1) and (temp.r<=r0) and (temp.c>=1) and (temp.c<=c0) then
        if (a[temp.r,temp.c]>temp.k) or (a[temp.r,temp.c]=-1) then
          range:=true;
    end;

  begin
    //with state do writeln(r,',',c,'=',k);
    if (state.r=rx) and (state.c=cx) then
      begin
        if (state.k<max) or (max=-1) then
          begin
            max:=state.k;
            imax:=i;
          end
        else if (state.k=max) and (imax>i) then imax:=i;
      end
    else
      begin
        temp.k:=state.k+1;
        for j:=1 to 8 do
          begin
            case j of
                1:begin
                    temp.r:=state.r-1;
                    temp.c:=state.c-2;
                  end;
                2:begin
                    temp.r:=state.r-1;
                    temp.c:=state.c+2;
                  end;
                3:begin
                    temp.r:=state.r+1;
                    temp.c:=state.c-2;
                  end;
                4:begin
                    temp.r:=state.r+1;
                    temp.c:=state.c+2;
                  end;
                5:begin
                    temp.r:=state.r-2;
                    temp.c:=state.c-1;
                  end;
                6:begin
                    temp.r:=state.r-2;
                    temp.c:=state.c+1;
                  end;
                7:begin
                    temp.r:=state.r+2;
                    temp.c:=state.c-1;
                  end;
                8:begin
                    temp.r:=state.r+2;
                    temp.c:=state.c+1;
                  end;
              end;
            if range(temp) then
              begin
                inc(qsave);
                queue[qsave]:=temp;
                a[temp.r,temp.c]:=temp.k;
              end;
          end;
        inc(qtake);
        if qtake<=qsave then
          if (max=-1) or (max>queue[qtake].k) then check(queue[qtake]);
      end;
  end;

begin
  readln(r0,c0,n);
  for i:=1 to n do readln(ri[i],ci[i]);
  readln(rx,cx);
  max:=-1;
  for i:=1 to r0 do
    for j:=1 to c0 do a[i,j]:=-1;
  for i:=1 to n do
    begin
      state.r:=ri[i];
      state.c:=ci[i];
      state.k:=0;
      qtake:=0;
      qsave:=0;
      //writeln('Kuda #',i);
      check(state);
    end;
  if max=-1 then writeln(max)
    else writeln(max,' ',imax);
end.
