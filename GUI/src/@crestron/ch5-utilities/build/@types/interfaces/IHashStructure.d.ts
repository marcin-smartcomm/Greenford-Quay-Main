export interface IHashStructure {
    name: string;
    hash: string;
    children?: Array<IHashStructure>;
}
