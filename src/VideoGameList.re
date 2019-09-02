/* VideoGameList.re */
open VideoGame;

let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("VideoGameList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
    <ul style={ReactDOMRe.Style.make(~listStyleType="none", ())}>
      {
        items
        |> Array.map(videoGameFromJs)
        |> Array.map(item =>
             <li key={item.id}>
               <input
                id={item.id}
                type_="checkbox"
                checked={item.completed}
               />
               <label htmlFor={item.id}>
                 {item.title ++ " | " ++ item.developer |> str}
               </label>
             </li>
           )
        |> ReasonReact.array
      }
    </ul>,
};
