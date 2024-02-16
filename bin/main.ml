
open Mlcpp_filesystem

let () = print_endline "Hello, World!";
         (* Filesystem.set_cwd(".."); *)
         print_endline ("cwd: " ^ (Filesystem.Path.to_string @@ Filesystem.get_cwd ()));
         let fp = Filesystem.Path.from_string "dune-project" in
         if Filesystem.Path.exists fp
         then let p2 = Filesystem.Permissions.from_oct 755 in (* rwxr_xr_x *)
              Filesystem.Permissions.set fp p2 |> ignore
         else print_endline "not found.";
         if Filesystem.Path.exists fp
         then let p2 = Filesystem.Permissions.from_oct 020 in (* g + w *)
              Filesystem.Permissions.add fp p2 |> ignore
         else print_endline "not found.";
         if Filesystem.Path.exists fp
         then let p2 = Filesystem.Permissions.from_oct 111 in  (* no x *)
              Filesystem.Permissions.remove fp p2 |> ignore
         else print_endline "not found.";
         if Filesystem.Path.exists fp
         then
           let perms = Filesystem.Permissions.get fp in
           match perms with
           | None -> print_endline "failure getting permissions"
           | Some p' ->
                Printf.printf "%s (a %s)  fsize: %d   perms: o%d (%d) (%s)\n"
                (Filesystem.Path.to_string fp)
                (Filesystem.Path.path_type fp)
                (Filesystem.Path.file_size fp)
                (Filesystem.Permissions.to_oct p')
                (Filesystem.Permissions.to_dec p')
                (Filesystem.Permissions.to_string p')
         else print_endline "not found.";

         let p2 = Filesystem.Permissions.from_oct 755 in
         Printf.printf "permissions octal: o%d dec: %d string: %s\n"
           (Filesystem.Permissions.to_oct p2)
           (Filesystem.Permissions.to_dec p2)
           (Filesystem.Permissions.to_string p2);

         let space = Filesystem.space @@ Filesystem.get_cwd () in
         Printf.printf "space: len = %d   capacity: %d  free: %d  available: %d\n"
           (List.length space) (List.hd space) (List.hd (List.tl space)) (List.hd (List.tl @@ List.tl space));

         let tmpdir = Filesystem.Path.temp_directory () in
         Printf.printf "temporary directory: %s\n" (Filesystem.Path.to_string tmpdir);

         let testfile = Filesystem.Path.from_string "/tmp/test101/some_file.dat" in
         Printf.printf "file %s: has ext = %s; filename = %s; in dir = %s; root = %s\n"
           (Filesystem.Path.to_string testfile)
           (Filesystem.Path.to_string @@ Filesystem.Path.extension testfile)
           (Filesystem.Path.to_string @@ Filesystem.Path.filename testfile)
           (Filesystem.Path.to_string @@ Filesystem.Path.parent testfile)
           (Filesystem.Path.to_string @@ Filesystem.Path.root testfile);

         let dir = Filesystem.Path.from_string "." in
         Filesystem.list_directory dir () (fun de () ->
           let fp = Filesystem.Direntry.as_path de in
           let (fid, fsz) = if Filesystem.Direntry.is_regular_file de then ("f", Filesystem.Direntry.file_size de)
           else if Filesystem.Direntry.is_directory de then ("D",0)
           else ("*",0) in
           Printf.printf "%s %d %s\n" fid fsz (Filesystem.Path.to_string fp) 
         );

         let count = Filesystem.list_directory dir 0 (fun de cnt ->
          let fp = Filesystem.Direntry.as_path de in
          let (fid, fsz) = if Filesystem.Direntry.is_regular_file de then ("f", Filesystem.Direntry.file_size de)
          else if Filesystem.Direntry.is_directory de then ("D",0)
          else ("*",0) in
          let _ = Printf.printf "%s %d %s\n" fid fsz (Filesystem.Path.to_string fp)
          in (cnt + 1)
         )
         in Printf.printf "counted %d files and directories\n" count;

         let dirs = Filesystem.list_directory dir [] (fun de ds ->
          let fp = Filesystem.Direntry.as_path de in
          let (fid, fsz) = if Filesystem.Direntry.is_regular_file de then ("f", Filesystem.Direntry.file_size de)
          else if Filesystem.Direntry.is_directory de then ("D",0)
          else ("*",0) in
          let _ = Printf.printf "%s %d %s\n" fid fsz (Filesystem.Path.to_string fp)
          in if fsz = 0 then ((Filesystem.Path.to_string fp) :: ds) else ds
         )
         in Printf.printf "counted %d directories\n" (List.length dirs);
         Printf.printf "%s\n" (List.fold_left (fun agg dn -> agg ^ "  " ^ dn) "" dirs);

         let space = Filesystem.space (Filesystem.Path.from_string "/") in
         begin
           Printf.printf "space: "; List.iteri (fun i nsz -> Printf.printf "  %d:%d " i nsz) space;
           Printf.printf "\n"
         end