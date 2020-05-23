type
  widget=record
    nama,tipe:string;
    x,y,border,space:longint;
  end;

var

  list:array[1..100] of widget;

function find(temp:string):longint;
  var
    i:longint;

  begin
    for i:=1 to n do
      if list[i].nama=temp then exit(i);
    exit(0);
  end;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a)
      else exit(b);
  end;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

begin
  readln(ntask); n:=0;
  for t:=1 to ntask do
    begin
      readln(task);
      if copy(task,1,6)='Widget' then
        begin
          p:=7; temp:='';
          repeat
            inc(p);
            if task[p]='(' then break
              else temp:=temp+task[p];
          until false;
          q:=pos('.',task); num1:=copy(task,p+1,q-p-1); num2:=copy(task,q+1,length(task)-q-1);
          inc(n);
          with list[n] do
            begin
              nama:=temp;
              tipe:='none';
              border:=0; space:=0;
              val(num1,x); val(num2,y);
            end;
        end
      else if copy(task,1,4)='HBox' then
        begin
          inc(n);
          with list[n] do
            begin
              nama:=copy(6,length(task)-5);
              tipe:='HBox';
              border:=0; space:=0;
              x:=0; y:=0;
            end;
        end
      else if copy(task,1,4)='VBox' then
        begin
          inc(n);
          with list[n] do
            begin
              nama:=copy(6,length(task)-5);
              tipe:='VBox';
              border:=0; space:=0;
              x:=0; y:=0;
            end;
        end
      else
        begin
          p:=pos('.',task);
          temp:=copy(task,1,p-1);
          if copy(task,p+1,4)='pack' then
            begin
              a:=find(temp);
              b:=find(copy(task,p+6,length(task)-p-6););
              con[a,b]:=true;
              inc(nchild[a]); child[a,nchild[a]]:=b;
              par[b]:=a;
              q:=a;
              while q<>0 do
                begin
                  with list[q] do
                    if tipe='HBox' then
                      begin
                        x:=x+space+list[b].x;
                        y:=max(y,2*border+list[b].y);
                      end
                    else if tipe='VBox' then
                      begin
                        x:=max(x,2*border+list[b].x);
                        y:=y+space+list[b].y;
                      end;
                 q:=par(q);
                end;
            end
          else if copy(task,p+1,10)='set_border' then
            begin
              a:=find(temp);
              temp:=copy(task,p+12,length(task)-p-12);
              val(temp,z);

            end;
        end;
    end;
end.
